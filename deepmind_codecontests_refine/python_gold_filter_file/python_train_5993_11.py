n=int(input())
s=input()
s1='_'
while s.find('(')!=-1:
    beg=s.find('(')
    end=s.find(')')
    s1=s1+s[beg+1:end]+'_'
    s=s[:beg]+'_'+s[end+1:]
a=[len(i) for i in s.split('_') if i]
b=[i for i in s1.split('_') if i]
print(max(a) if len(a)>0 else 0,len(b))
