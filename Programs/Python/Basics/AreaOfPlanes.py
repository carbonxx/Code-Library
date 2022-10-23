import math
pi= math.pi
n=int(input("Area of:\n1.Rectangle\n2.Triangle\n3.Circle\n"))
if(n==1):
    a=int(input("Enter a value\n"))
    b=int(input("Enter b value\n"))
    area= a*b
    print("Area of Rectangle is ",area)
elif(n==2):
    b=int(input("Enter b value\n"))
    h=int(input("Enter h value\n"))
    area= 0.5*b*h
    print("Area of Triangle is ",area)
elif(n==3):
    r=int(input("Enter r value\n"))
    area= pi*r*r
    print("Area of Circle is ",area)
else:
    print("Wrong entry!!")