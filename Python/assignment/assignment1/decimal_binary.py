number = int(input("Enter a numberto convert into binary : "))
result = "" 
while number != 0:
    remainder = number % 2  
    number = number // 2
    result = str(remainder) + result
print("The binary representation is", result)