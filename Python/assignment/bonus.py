salary=int(input('Enter your current salary :'))
gender=input('Enter your gender :')

if gender=='female' and salary<25000 :
    bonus_salary= salary+salary*0.25+salary*0.05
    print('Rs.',bonus_salary,'is your Diwali Bonus')
elif gender=='female' and salary>=25000 :
    bonus_salary= salary+salary*0.25
    print('Rs.',bonus_salary,'is your Diwali Bonus')
elif gender=='male' and salary<25000 :
    bonus_salary= salary+salary*0.20+salary*0.05
    print('Rs.',bonus_salary,'is your Diwali Bonus')
elif gender=='male' and salary>=25000 :
    bonus_salary= salary+salary*0.20
    print('Rs.',bonus_salary,'is your Diwali Bonus')

