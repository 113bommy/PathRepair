def days(n):
    if n%400==0 or n%4==0 and n%100!=0:
        return 366
    else:
        return 365

n = int(input())
leap = days(n)

inicial=0
for act in range(n+1,100000+1):
    inicial=(inicial+days(act)%7)%7
    if inicial==0 and days(act)==leap:
        print(act)
        break
