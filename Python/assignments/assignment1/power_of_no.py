# Python Program to find Power of a Number
num = int(input(" Please Enter any Positive Integer : "))
expo = int(input(" Please Enter Exponent Value : "))
pow = 1
i = 1
while(i <= expo):
    pow = pow * num
    i = i + 1
print("The Result of {0} Power {1} = {2}".format(num, expo, pow))