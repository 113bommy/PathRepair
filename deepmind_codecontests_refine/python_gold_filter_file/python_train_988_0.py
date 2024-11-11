nx,bx = map(int,input().split())

ar_x = list(map(int,input().split()))

ny,by = map(int,input().split())

ar_y = list(map(int,input().split()))

ans_y,ans_x = 0,0
cnt = 0
for i in ar_y[::-1]:
    ans_y = ans_y+i*(by**cnt)
    cnt+=1

cnt =0
for i in ar_x[::-1]:
    ans_x = ans_x+i*(bx**cnt)
    cnt+=1
if ans_x == ans_y:
    print("=")
elif ans_x < ans_y:
    print("<")
else:
    print(">")