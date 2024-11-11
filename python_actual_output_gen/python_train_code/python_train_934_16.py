n =int(input())
capital= ['A','B','C','D','E','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y','Z']  
linha= input().split()
sum_max=0
for palavra in linha:
    s=0
    for ch in palavra:
        if ch in capital:
           s+=1
           if s>sum_max:
               sum_max=s
print(sum_max)