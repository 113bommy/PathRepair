run,vis,cook = map(int,input().split())
cir=(run+vis-1)//vis;
print(cir)
cirt=int(cir)*vis;
circ=(run+cirt);
ans=(int(2)*int(cook))//int(circ)*int(cirt);
print(ans)
rest=(2*cook)%(run+cir*vis);
if(2*run>=rest):
    dans=ans+rest/2.0;
else:
    dans=ans+run+(rest-2*run);

print(dans)
