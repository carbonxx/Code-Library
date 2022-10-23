n = int(input("Enter the number of terms\n"))
n1, n2 = 0, 1
count = 0
if n <= 0:
   print("Wrong Entry!!!")
elif n == 1:
   print("Fibonacci sequence upto",n,":")
   print(n1)
else:
   print("Fibonacci sequence upto",n,":")
   while count < n:
       print(n1)
       nth = n1 + n2
       n1 = n2
       n2 = nth
       count += 1
