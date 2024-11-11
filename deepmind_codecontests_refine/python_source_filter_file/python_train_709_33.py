n=int(input())
a=list(map(int,input().split()))

cnt1,cnt2=0,0
for i in a:
    if i%2!=0:
        cnt1+=1
    if i%4==0:
        cnt2+=1
print('Yes' if cnt2>=cnt1 or (len(a)==3 and cnt2+1>=cnt1) else 'No')