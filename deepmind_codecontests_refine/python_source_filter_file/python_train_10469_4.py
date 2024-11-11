inp=input()
sum=min(abs(ord(inp[0])%96-ord('a')%96),26-abs(ord(inp[0])%96-ord('a')%96))
for i in range(len(inp)-1):
    sum+=min(abs(ord(inp[i])%96-ord(inp[i+1])%96),26-abs(ord(inp[i])%96-ord(inp[i+1])%96))
    print(min(abs(ord(inp[i])%96-ord(inp[i+1])%96),26-abs(ord(inp[i])%96-ord(inp[i+1])%96)))
    
    
print(sum)