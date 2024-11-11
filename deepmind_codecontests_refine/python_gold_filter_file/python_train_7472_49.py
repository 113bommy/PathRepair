n=int(input())
arr1=[]
arr2=[]
for _ in range(n):
  s=input()
  cnt1=0
  cnt2=0
  for i in range(len(s)):
    if s[i]=='(':
      cnt1+=1
    else:
      if cnt1==0:
        cnt2+=1
      else:
        cnt1-=1
  if cnt1-cnt2>=0:
    arr1.append([cnt1,cnt2])
  else:
    arr2.append([cnt1,cnt2])
arr1=sorted(arr1,key=lambda x:x[1])
arr2=sorted(arr2,reverse=True,key=lambda x:x[0])
arr=arr1+arr2
cnt=0
for a,b in arr:
  if b>cnt:
    print('No')
    break
  else:
    cnt+=a-b
else:
  if cnt==0:
    print('Yes')
  else:
    print('No')