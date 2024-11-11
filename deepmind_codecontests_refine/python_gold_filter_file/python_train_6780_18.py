def cleanup(s):
      m=""
      for i in range(len(s)):
            if(s[i]!="?" and s[i]!="*"):
                  m+=s[i]
      return(m)

def delete(s,k):
      m=""
      for i in range(len(s)):
            if(i!=k):
                  m+=s[i]
      return(m)

def multiply(s,k,n):
      m=""
      for i in range(len(s)):
            if(i!=k):
                  m+=s[i]
            else:
                  for j in range(n+1):
                        m+=s[i]
      x=cleanup(m)
      return(x)
      

s=input()
k=int(input())
m=0
q=0
st=0
a=""
for i in range(len(s)):
      if(s[i]=="?"):
            q+=1
      elif(s[i]=="*"):
            st+=1
            
      else:
            m+=1
            a+=s[i]
if(k<(m-q-st) or (k>m and st==0)):
      print("Impossible")
else:
      if(k==m):
            print(a)
      elif(k>m):
            for i in range(len(s)):
                  if(s[i]=="*"):
                        m=multiply(s,i-1,k-m)
                        break
            print(m)
      else:
            diff=m-k
            for i in range(len(s)):
                  if(diff):
                        if(s[i]=="?" or s[i] =="*"):
                              s=delete(s,i-1)
                              diff-=1
                  else:
                        break
            print(cleanup(s))
            
            
