library(ISLR)
library(glmnet)
#install.packages("leaps")
#install.packages("glmnet")


#RIDGE and LASSO
################################

fix(Hitters)
names(Hitters)

dim(Hitters)
sum(is.na(Hitters$Salary))

# remove obs with MV
Hitters =na.omit(Hitters)
dim(Hitters)
sum(is.na(Hitters$Salary))

x=model.matrix (Salary~.,Hitters )[,-1] #-1 removes the constant
y=Hitters$Salary



grid =10^seq(10,-2, length =100)
#lambda = 10^10 to lambda = 10-2 , i.e. from no features to OLS

ridge.mod =glmnet (x,y,alpha =0, lambda =grid) # alpha=0 means ridge. alpha=1 means LASSO
#variables are standardized

#Accessing coefs - 19 features and 100 lambda
dim(coef(ridge.mod ))

# When lambda is large, expect smaller coeffs
###########################################
ridge.mod$lambda [50]
coef(ridge.mod)[,50]

ridge.mod$lambda [60]
coef(ridge.mod)[,60]

# using predict
##########################################################
# a new lambda =50
predict(ridge.mod ,s=50, type ="coefficients")[1:20 ,]


#Estimate the test MSE
#######################################
set.seed (1)
train=sample(1:nrow(x), nrow(x)/2)
test=(-train )
y.test=y[test]

# estimate ridge on test set and predict for lambda =4
ridge.mod = glmnet (x[train ,],y[train],alpha =0, lambda =grid ,thresh =1e-12)
ridge.pred = predict (ridge.mod ,s=4, newx=x[test ,])
mean(( ridge.pred -y.test)^2)


# estimate ridge on test set and predict for lambda =10^10
ridge.pred=predict(ridge.mod ,s=1e10 ,newx=x[test ,])
mean(( ridge.pred -y.test)^2)

#OLS lambda=0
ridge.pred = predict(ridge.mod ,s=0, newx=x[test,])
mean(( ridge.pred -y.test)^2)

# To do: choose lamda with CV.



#LASSO
##############################################

lasso.mod <- glmnet(x[train , ], y[train], alpha = 1,lambda = grid)
plot(lasso.mod)

#cross validation
set.seed (1)
cv.out <- cv.glmnet(x[train , ], y[train], alpha = 1) #10-fold CV
plot(cv.out)
bestlam <- cv.out$lambda.min
lasso.pred <- predict(lasso.mod , s = bestlam ,
newx = x[test , ])
mean (( lasso.pred - y.test)^2)

out <- glmnet(x, y, alpha = 1, lambda = grid)
lasso.coef <- predict(out , type = "coefficients",s = bestlam)[1:20, ]
lasso.coef
lasso.coef[lasso.coef != 0]
