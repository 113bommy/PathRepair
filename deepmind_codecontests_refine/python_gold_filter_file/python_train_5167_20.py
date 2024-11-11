# [last appearence,max len diff]
hash={}
s=input()
for i in range(len(s)):
  if(s[i] in hash):
    if i-hash[s[i]][0] > hash[s[i]][1]:
      hash[s[i]][1]=i-hash[s[i]][0]
    hash[s[i]][0]=i
  else:
    hash[s[i]]=[i,i+1]

chars=set([i for i in s])

for i in hash.keys():
  if((len(s))-hash[i][0]) > hash[i][1]:
    hash[i][1]=(len(s))-hash[i][0]
  hash[i][0]=len(s)-1

mini=len(s)
for i in hash.keys():
  if hash[i][1]< mini:
    mini=hash[i][1]


print(mini)