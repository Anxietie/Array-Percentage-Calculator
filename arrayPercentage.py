#Initialize the dictionary
stored_occurred = {}
#Get input
input = input("Type all values in one line separated by a space: ")
#turn the input into an array
inpArr = input.split()
#Cast all elements of the input to integers for further use
for i in range(len(inpArr)):
    inpArr[i] = int(inpArr[i])
for i in range(len(inpArr)):
    if stored_occurred.get(inpArr[i]):
        stored_occurred[inpArr[i]] += 1
    else:
        stored_occurred[inpArr[i]] = 1
#Create an iterable list of the occurrences
dictValues = list(stored_occurred.values())
#Create function to get the number with the most occurrences, as well as the amount of occurrences
def getMaxs():
    localMax = 0
    localKey = 0
    for i in range(len(dictValues)):
        if dictValues[i] > localMax:
            localKey = i
            localMax = dictValues[i]
    globalMax = localMax
    return localKey+1, localMax
#Assign key and max to the values
key, max = getMaxs()
#Arithmetic for easier printing
computed = (float(max)/len(inpArr))*100
mod = '%'
print(str(key)+" has the highest chance with "+mod+str(computed))
