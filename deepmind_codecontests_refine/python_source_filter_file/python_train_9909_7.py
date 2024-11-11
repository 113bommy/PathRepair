rib=int(input())
dol_in_rib=int(input())
eur_in_rib=int(input())*5
rib%=min(dol_in_rib,eur_in_rib)*100
i,j,min_rib=0,0,101
while i<=rib//dol_in_rib+1:
    j=0
    while j<=(rib-i*dol_in_rib)//eur_in_rib+1:
        current_rib=rib-i*dol_in_rib-j*eur_in_rib
        if current_rib<min_rib and current_rib>-1:
            min_rib=current_rib
        j+=1
    i+=1
print(min_rib)
