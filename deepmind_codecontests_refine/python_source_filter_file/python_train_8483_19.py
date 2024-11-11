#week1-7
#https://codeforces.com/problemset/problem/581/A

line=input().split()

a=int(line[0])
b=int(line[1])

if a==b:
    day1=a//2
    day2=0
elif a>b:
    day1=b
    day2=(a-b)//2
elif a<b:
    day1=a
    day2=(b-a)//2

print(day1,day2)
    
