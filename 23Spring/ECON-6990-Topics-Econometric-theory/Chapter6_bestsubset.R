library(ISLR)
#install.packages("leaps")


#Best subset
################################

fix(Hitters)
names(Hitters)

dim(Hitters)
sum(is.na(Hitters$Salary))

# remove obs with MV
Hitters =na.omit(Hitters)
dim(Hitters)
sum(is.na(Hitters$Salary))

Perform best subset with 8 features
####################################
library(leaps)# library for best subset
regfit.full=regsubsets(Salary~.,Hitters)
summary(regfit.full)


#Note:
#An asterisk indicates that a given variable is included in the corresponding
#model. For instance, this output indicates that the best two-variable model
#contains only Hits and CRBI.

# set the number of features (default above is 8)
####################################################
regfit.full=regsubsets (Salary~.,data=Hitters ,nvmax =19)
reg.summary =summary(regfit.full)
names(reg.summary )
reg.summary$rsq

# Plots
###############################################
par(mfrow =c(2,2)) #declare 4 figures in 2X2 matrix 

plot(reg.summary$rss ,xlab=" Number of Variables ",ylab=" RSS",type="l")
plot(reg.summary$adjr2 ,xlab =" Number of Variables ",ylab=" Adjusted RSq",type="l")
which.max (reg.summary$adjr2)#index of maximum
#11
points(11, reg.summary$adjr2[11], col ="red",cex =2, pch =20)


plot(reg.summary$cp , xlab = "Number of Variables", ylab="Cp", type = "l")
which.min(reg.summary$cp )
#10
points (10, reg.summary$cp [10], col ="red",cex =2, pch =20)
which.min (reg.summary$bic )
# 6
plot(reg.summary$bic ,xlab=" Number of Variables ",ylab=" BIC",type= "l")
points(6, reg.summary$bic [6], col =" red",cex =2, pch =20)


plot(regfit.full ,scale ="r2")
plot(regfit.full ,scale ="adjr2")
plot(regfit.full ,scale ="Cp")
plot(regfit.full ,scale ="bic")
#The regsubsets() function has a built-in plot() command which can
#be used to display the selected variables for the best model with a given
#number of predictors, ranked according to the BIC, Cp, adjusted R2, or
#AIC. To find out more about this function, type ?plot.regsubsets.







# Fwd and Bwd selection
##############################################

regfit.fwd = regsubsets(Salary~.,data=Hitters ,nvmax =19,method ="forward")
summary (regfit.fwd )
#Note : CRBI will be in all models

regfit.bwd=regsubsets (Salary~.,data=Hitters ,nvmax =19,method ="backward")
summary (regfit.bwd )




# Validation set to choose among models
##############################################

#Create random train and test sets
set.seed (1)
train=sample (c(TRUE ,FALSE), nrow(Hitters ),rep=TRUE)
test =(!train )

Best subset on train data
#########################
regfit.best=regsubsets (Salary~.,data=Hitters[train ,],nvmax =19)
test.mat = model.matrix(Salary~.,data=Hitters[test ,])

A Loop across the 19th models
############################
val.errors =rep(NA ,19) #placeholder
for(i in 1:19){
coefi=coef(regfit.best ,id=i)                       # current coeff
pred=test.mat[,names(coefi)]%*% coefi               # XBeta
val.errors[i]= mean(( Hitters$Salary[test]-pred)^2) # record test MSE
}
which.min (val.errors )



# Finally Get coeffs using the best model on the full data set
regfit.best=regsubsets (Salary~.,data=Hitters ,nvmax =19)
coef(regfit.best ,7)


# A function that does prediction as above
predict.regsubsets =function (object ,newdata ,id ,...){
form=as.formula(object$call [[2]])
mat=model.matrix form ,newdata )
coefi =coef(object,id=id)
xvars =names (coefi )
mat[,xvars ]%*% coefi
}



#To do: K-fold CV








