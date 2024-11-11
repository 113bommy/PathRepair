H,W=map(int,input().split())
answer=0
if not H%3==0 and not W%3==0:
  S_1=[H//3*W,(H-H//3)*(W//2),(H-H//3)*(W-W//2)]
  S_2=[(H//3+1)*W,(H-H//3-1)*(W//2),(H-H//3-1)*(W-W//2)]
  S_3=[W//3*H,(W-W//3)*(H//2),(W-W//3)*(H-H//2)]
  S_4=[(W//3+1)*H,(W-W//3-1)*(H//2),(W-W//3-1)*(H-H//2)]
  answer=min(max(S_1)-min(S_1),max(S_2)-min(S_2),max(S_3)-min(S_3),max(S_4)-min(S_4),H,W)
print(answer)