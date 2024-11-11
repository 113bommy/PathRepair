n=int(input())
s=list(input())
i,count=1,0
while i<n:
      if s[i]==s[i-1]=="a":
            s[i]="b"
            count+=1
      elif s[i]==s[i-1]=="b":
            s[i]="a"
            count+=1
      i+=2
print(count)
print(s)