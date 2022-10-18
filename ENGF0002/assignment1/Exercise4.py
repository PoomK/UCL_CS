#Calculating Pi using Monte Carlo Method

import random

def estimate_pi():

    #Create variables to store number of hits and total
    NHit = 0
    NTotal = 0

    for i in range(1,1000):

        #Generate random coordinates
        xcoord = random.uniform(0,1)
        ycoord = random.uniform(0,1)

        #Get distance of coordinates from centre of circle
        if xcoord>0.5:
            xdistance = xcoord - 0.5
        else:
            xdistance = 0.5 - xcoord
        if ycoord>0.5:
            ydistance = ycoord - 0.5
        else:
            ydistance = 0.5 - ycoord

        #Check whether point is in circle
        originDist = xdistance**2 + ydistance**2
        if originDist <= 1/4:
            NHit += 1

        NTotal += 1

        pi = 4 * NHit / NTotal

        i += 1

    return pi

print(str(estimate_pi()))