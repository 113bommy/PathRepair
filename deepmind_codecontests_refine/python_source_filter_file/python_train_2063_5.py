import sys
from collections import deque
l,n=map(int,input().split())
c=n
tree1=[int(i) for i in sys.stdin]
reversed_tree1=[l-i for i in reversed(tree1)]
tree=deque(tree1)
reversed_tree=deque(reversed_tree1)
if n%2 == 0:
  ans= sum(tree1)*2 + l*(n-1) +tree1[n//2] - sum(tree1[n//2:])*4
  ans2= sum(reversed_tree1)*2 + l*(n-1) +reversed_tree1[n//2] - sum(reversed_tree1[n//2:])*4
  n-=1
  c-=1
  ans3= ans-tree.popleft()*2-l+tree[n//2]*2
  ans= max(ans,ans3)
  ans4= ans2-reversed_tree.popleft()*2-l+(reversed_tree[n//2])*2
  ans2= max(ans2,ans4)
else:
  ans= sum(tree1)*2 + l*(n-1) - tree1[n//2] - sum(tree1[((n//2)+1):])*4
  ans3=ans
  ans2= sum(reversed_tree1)*2 + l*(n-1) - reversed_tree1[n//2] - sum(reversed_tree1[((n//2)+1):])*4
  ans4=ans2
for i in range(n//2):
  n-=1
  ans_stack= ans3-tree.popleft()*2-l+tree[(n-1)//2]+tree[(n+1)//2]
  ans= max(ans_stack,ans)
  ans3=ans_stack
  n-=1
  ans_stack= ans3-tree.popleft()*2-l+tree[n//2]*2
  ans=max(ans_stack,ans)
  ans3=ans_stack
n=c
for i in range(n//2):
  n-=1
  ans_stack= ans4-reversed_tree.popleft()*2-l+reversed_tree[(n-1)//2]+reversed_tree[(n+1)//2]
  ans2=max(ans_stack,ans2)
  ans4=ans_stack
  n-=1
  ans_stack= ans4-reversed_tree.popleft()*2-l+reversed_tree[n//2]*2
  ans2=max(ans2,ans_stack)
  ans4=ans_stack
print(max(ans,ans2))
