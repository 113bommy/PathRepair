#商をxとすると、(m+1)*x=N
#つまり、約数のうち、商よりも大きいもの−１の和を求める
n=int(input())
ans=0
for i in range(1, int(n**0.5)+1):
  if n%i==0:
    if n/i-1 > i:
      ans+=(n//i)-1
print(ans)