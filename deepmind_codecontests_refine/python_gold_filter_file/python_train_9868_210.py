n,r=map(int,input().split())
rate= r if n>=10 else r+100*(10-n)
print(rate)