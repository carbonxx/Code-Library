income=int(input('Enter the total income :'))
if income < 300000 :
    print('No tax needed to be paid')
elif income>=300000 and income<500000 :
    tax=income * 0.1
    print('Rs.',tax,'is the total tax')
elif income>=500000 and income<1000000 :
    tax=income*0.02
    print('Rs.',tax,'is the total tax')
else :
    tax=income*0.03
    print('Rs.',tax,'is the total tax')
