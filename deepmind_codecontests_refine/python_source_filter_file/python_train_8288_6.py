Way = input()
L1 = input()
L2 = input()

WayB = Way[::-1]
forw = True
back = True

if ((Way.find(L1) == -1) or (Way.rfind(L2) == -1)) and ((WayB.find(L1) == -1) or (WayB.rfind(L2) == -1)):
    print('fantasy')
else:
    if Way.find(L1) + len(L1) > Way.rfind(L2):
        forw = False
    if WayB.find(L1) + len(L2) > WayB.rfind(L2):
        back = False

    if forw and back:
        print('both')
    if (not forw) and back:
        print('backward')
    if forw and (not back):
        print('forward')
    if (not forw) and (not back):
        print('fantasy')
