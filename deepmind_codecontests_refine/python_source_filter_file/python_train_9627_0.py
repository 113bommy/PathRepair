alpha=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'g', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
dict_s={}
dict_news={}
s=list(input())
newspaper=list(input())
for i in alpha:
    dict_s.update({i:s.count(i)})
    dict_news.update({i:newspaper.count(i)})
ny=0
for k in alpha:
    if dict_s[k]<=dict_news[k]:
        ny+=dict_s[k]
        dict_news[k]-=dict_s[k]
        dict_s[k]=0
    else:
        ny+=dict_news[k]
        dict_s[k]-=dict_news[k]
        dict_news[k]=0
nw=0
for k in alpha:
    if k.isupper() and dict_s[k]!=0:
        kl=k.lower()
        nw+=min([dict_s[k],dict_news[kl]])
    if k.islower() and dict_s[k]!=0:
        ku=k.upper()
        nw+=min([dict_s[k],dict_news[ku]])
print(ny,nw)
