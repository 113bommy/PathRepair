a,b,c,d=list(input())
op=lambda i,a:"+" if i&a else "-"
for i in range(8):
  s=a+op(i,1)+b+op(i,2)+c+op(i,4)+d
  if eval(s)==7:print(s+"=7");exit()