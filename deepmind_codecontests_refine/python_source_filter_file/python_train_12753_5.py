l = int(input())
Hs = int(input())
VMs = int(input())

spdRap = Hs+VMs

firstHit = (l*Hs/spdRap)

VMdistH0 = (firstHit/Hs*VMs)

if VMdistH0 >= l-firstHit:
    VMposH0 = VMdistH0 - (l-firstHit)
    secHit = (l-VMposH0)*Hs/spdRap
else:
    if (l/Hs) <= (((l-firstHit)-VMdistH0)/VMs):
        secHit = ((firstHit + VMdistH0)/(Hs-VMs))*Hs
    else:
        posHSVM0 = ((1-firstHit)-VMdistH0)/VMs*Hs
        secHit = (l-posHSVM0)*Hs/spdRap + posHSVM0
        
print(secHit)