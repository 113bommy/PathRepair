n,m=map(int,input().split())
str1=list(input().split())
str2=list(input().split())
for i in range (int(input())):
    year=int(input())
    year1=year
    if(year>max(n,m)):
        year%=max(n,m)
    if(year1>min(n,m)):
            year1%=min(n,m)
    if(m>n):
        print(str1[year1-1]+str2[year-1])
    elif(n<=m):
        print(str1[year-1]+str2[year1-1])