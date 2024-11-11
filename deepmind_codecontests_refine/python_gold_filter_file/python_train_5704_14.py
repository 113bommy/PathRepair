def main():
  import sys
  input=sys.stdin.buffer.readline
  h,w=map(int,input().split())
  s=input()
  a=b=x=y=s[0]==35
  d=[(b,a)]
  for i in range(1,w):
    f=s[i]==35
    b+=a^f
    a=f
    d+=(b,a),
  for _ in range(1,h):
    s=input()
    f=s[0]==35
    y+=x^f
    b=y
    a=x=f
    p=[(b,a)]
    for i in range(1,w):
      f=s[i]==35
      b+=a^f
      c,g=d[i]
      c+=f^g
      if b>c:b=c
      a=f
      p+=(b,a),
    d=p
  print(b+1>>1)
main()