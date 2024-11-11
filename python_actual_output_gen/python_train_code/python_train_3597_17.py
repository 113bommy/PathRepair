a=input()
b=a[0]
c=a[1]
if (b=="a" and c=="1") or (b=="a" and c=="8") or (b=="h" and c=="1") or (b=="h" and c=="8"):
 print("3")
elif (b=="a") or (b=="h") or (b=="1") or (b=="8"):
 print("5")
else:
 print("8")
