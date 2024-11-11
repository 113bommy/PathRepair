n=input()

word=input()

countn=0
countz=0

for i in range(len(word)):

    if word[i]=='z':
        countz=countz+1
    elif word[i]=='n':
        countn=countn+1

out=list()


while countn>=1:
    out.append('1')
    countn=countn-1

while countz>=1:
    out.append('0')
    countz=countz-1

z=''.join(out)

print(z)