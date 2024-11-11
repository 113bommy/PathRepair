# import sys
# from ML_library.RandomForestTrain.RandomForestTrainHandler import RandomForestTrainHandler
#
# args = sys.argv
# class_entity = RandomForestTrainHandler(args)
# class_entity.execute()
 
 
# APPAPPPAPPPP
 
# # AAPAAPPAAPPP
#   AAPAAPPAAPPP
# # AAAAAAAAAAAP
num = input()
 
for i in range(int(num)):
    _ = input()
    listOfElems = input()
    # listOfElems = "PPA"
    indexPosList = [i for i in range(len(listOfElems)) if listOfElems[i] == 'A' ]
    # print(indexPosList)
    max_diff = 0
    for i,ele in enumerate(indexPosList):
        if i != len(indexPosList)-1:
            diff = indexPosList[i+1]-1 - ele
        else:
            # print("len(indexPosList)-1 - ele",len(listOfElems)-1 , ele)
            diff = len(listOfElems)-1 - ele
        # print("diff:",diff,"max_diff:",max_diff)
        if diff >= max_diff:
            max_diff = diff
    print(max_diff)