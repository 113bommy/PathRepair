# -------------------------------#
# INCLUDE <Amirhossein_Alimirzaei>
# INCLUDE <HajLorenzo>
# INCLUDE <mega16.h>
# Submit_Some_1000_ELO_:)
# -------------------------------#

a=['C','M','Y','G']
_EXE="#Black&White"
_EXEC=list(map(int,input().split()))
for i in range(_EXEC[0]):
    _0X=list(input().split())
    if(_EXE!="#Color"):
        for j in range(_EXEC[1]):
            if(_0X[j] in a):
                _EXE="#Color"
                break
print(_EXE)