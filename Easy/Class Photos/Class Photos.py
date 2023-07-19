def classPhotos(redShirtHeights, blueShirtHeights):
    redShirtHeights.sort()
    blueShirtHeights.sort()
    direction = False if redShirtHeights[0] > blueShirtHeights[0] else True
    for i in range(len(redShirtHeights)):
        if not direction and redShirtHeights[i] <= blueShirtHeights[i]:
            return False
        elif direction and redShirtHeights[i] >= blueShirtHeights[i]:
            return False

    return True
