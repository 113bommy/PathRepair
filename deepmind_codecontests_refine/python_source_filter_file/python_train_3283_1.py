_end = '_end_'
import sys
def add_trie(root,*words):
     global cnt
     for word in words:
         current_dict = root
         for letter in word:
             current_dict = current_dict.setdefault(letter, {})
         current_dict[_end] = _end
     return root
root=dict()
cnt=0
for s in sys.stdin:
    s=s.split('\\')
    root=add_trie(root,s)
    cnt+=1
    #if(cnt==2): break
def dfs(trie):
     #print(trie)
     #if(len(trie.keys())==1):
     if(trie==_end):
         return 1
     vls=len(trie.keys())
     for e in trie.keys():
         #print(e)
         if(e.count('.')):
             vls-=1
     if(vls==0):
         return len(trie.keys())
     ans=0
     for letter in trie.keys():
         ans+=dfs(trie[letter])
     return ans
def d2(trie):
    #print(trie)
    if(trie==_end):
        return -1
    vls=len(trie.keys())
    for e in trie.keys():
        #print(e)
        if(e.count('.')):
            vls-=1
    if(vls==0):
        return 0
    ans=0
    for letter in trie.keys():
        ans+=d2(trie[letter])+1
    return ans
ans=0
a2=0
for e in root.keys():
    for v in root[e].keys():
        ans=max(ans,dfs(root[e][v]))
for e in root.keys():
    for v in root[e].keys():
        a2=max(a2,d2(root[e][v]))
print(a2,ans)
