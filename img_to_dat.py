from PIL import Image

# image can be png or jpg format
fname = "./content/pictures/Lenna_512.png"
height = 512
width = 512
outdat = "./content/data/lenna512.dat"

def write_dat (f, pix_val):
    for i in range (0, len(pix_val)):
        f.write(str(pix_val[i])+"\n")
    f.close()

# get pixel values
print("Opening and processing image "+ fname+ " width "+str(width)+" height "+str(height))
im = Image.open(fname, 'r').convert("RGB")
pix_val = list(im.getdata())
im2 = Image.open(fname, 'r').convert("L")
pix_val_gray = list(im2.getdata())

print("total number of pixels: "+str(len(pix_val)))
print("total gray: "+str(len(pix_val_gray)))

#write dat file
print("Dat file written at "+outdat)
f = open( outdat, 'w')
write_dat (f, pix_val_gray)
