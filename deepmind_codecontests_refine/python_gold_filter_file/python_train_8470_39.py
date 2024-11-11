year = int(input())
while True:
    year+=1
    a = year%10
    b = (year//10)%10
    c = (year//100)%10
    d = (year//1000)%10
    if a!=b and a!=c and a!=d and b!=c and b!=d and c!=d:
        print(year)
        break

