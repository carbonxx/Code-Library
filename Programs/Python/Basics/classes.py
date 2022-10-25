# A program which uses oops concept in python


class Calc:
  def __init__(self, a:int, b:int):
    self.a = a
    self.b = b
    
  def sum(self):
    return a+b
  
  def diff(self):
    return a-b
  
  def multi(self):
    return a*b
  
  def quot(self):
    return a/b
  
  def mod(self):
    return a%b
  
  
# Use

r = Calc(2, 1)
print(r.sum)
print(r.diff)
print(r.multi)
print(r.quot)
print(r.mod)
