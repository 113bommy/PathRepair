import sys
input=sys.stdin.readline
s=input().rstrip()
mid=len(s)//2
l1=list("AHIMOoTUWwXxY")
flag=True
if len(s)%2==1:
  if not s[mid] in l1:
    flag=False
  i=1
  while mid-i>=0 and mid+i<len(s):
    if s[mid-i]!=s[mid+i]:
      if (s[mid-i]=="p" and s[mid+i]=="q") or (s[mid-i]=="q" and s[mid+i]=="p"):
        i+=1
        continue
      elif (s[mid-i]=="b" and s[mid+i]=="d") or (s[mid-i]=="d" and s[mid+i]=="b"):
        i+=1
        continue
      else:
        flag=False
        break
    else:
      if not s[mid-i] in l1:
        flag=False
        break
    i+=1
else:
  i=1
  while mid-i>=0 and mid+i-1<len(s):
    if s[mid-i]!=s[mid+i-1]:
      if (s[mid-i]=="p" and s[mid+i-1]=="q") or (s[mid-i]=="q" and s[mid+i-1]=="p"):
        i+=1
        continue
      elif (s[mid-i]=="b" and s[mid+i-1]=="d") or (s[mid-i]=="d" and s[mid+i-1]=="b"):
        i+=1
        continue
      else:
        flag=False
        break
    else:
      if not s[mid-i] in l1:
        flag=False
        break
    i+=1
if flag:
  print("TAK")
else:
  print("NIE")