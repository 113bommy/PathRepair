a,b,c=map(int,input().split())
print(b+c if c-b<=a else b+c-(c-b-a)//2)