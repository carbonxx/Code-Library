number = int(input("Enter the Number: "))
sum = 0
for value in range(1, number + 1):
    sum = sum + value
avg=sum/10
print('The sum of 10 natural numbers is',sum)
print('The average of 10 natural numbers is',avg)