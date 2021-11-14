n=int(input("Enter a number:"))
sum=0
while(n>0):
    dig=n%10
    sum=sum+dig
    n=n//10
print("The sumal sum of digits is:",sum)