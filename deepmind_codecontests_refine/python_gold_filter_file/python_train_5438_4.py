fuck = [
    'h','he','li','be','b','lv','nh','fl','mc','ts','og',
    'c','n','o','f','ne',
    'na','mg','al','si','p',
    's','cl','ar','k','ca',
    'sc','ti','v','cr','mn',
    'fe','co','ni','cu','zn',
    'ga','ge','as','se','br',
    'kr','rb','sr','y','zr',
    'nb','mo','tc','ru','rh',
    'pd','ag','cd','in','sn',
    'sb','te','i','xe','cs',
    'ba','la','ce','pr','nd','pm','sm','eu','gd','tb','dy','ho','er','tm','yb','lu',
    'hf','ta','w','re','os',
    'ir','pt','au','hg','tl',
    'pb','bi','po','at','rn',
    'fr','ra','ac','rf',
    'th','pa','u','np','pu','am','cm','bk','cf','es','fm','md','no','lr','db','sg','bh','hs','mt','ds','rg','cn']

def dfs(pos):
    global s,a
    if pos == len(s):
        a = 1
        return
    for i in fuck:
        if pos+len(i)<=len(s) and i == s[pos:pos+len(i)]:
            dfs(pos+len(i))
    return

s = input().strip().lower()
a = 0
dfs(0)
if a == 0:
    print("NO")
else:
    print("YES")