n = int(input())
a10 = ["zero","one","two","three","four","five","six","seven","eight","nine"]
a100 = ["ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
a20 = ["eleven","twelve","therteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
if n < 10: print(a10[n])
elif n % 10 == 0: print(a100[n//10-1])
elif n < 20: print(a20[n-11]) 
else:
    n = list(str(n))
    b = ""
    b += a100[int(n[0])-1]; b += "-"
    b += a10[int(n[1])-1]
    print(b)