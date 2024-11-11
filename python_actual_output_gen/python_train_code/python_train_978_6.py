k=int(input())
l=list(map(int,input().split()))
nowmax=2
nowmin=2
for i in range(k):
  num=l[-1-i]
  if nowmax-nowmin<num and nowmax%num>nowmin%num and not(nowmax%num==0 or nowmin%num==0):
    print(-1)
    exit()
  else:
    nowmax,nowmin=(nowmax//num)*num+num-1,(((nowmin-1)//num)+1)*num
print(nowmin,nowmax)