from PIL import Image

loc = "./content/pictures/"
dloc= "./content/data/"
fname = "New_Lenna_512.jpg"
outdat = "new_lenna512.dat"
height = 512
width = 512

def read_dat(file_path):
    with open(file_path, 'r') as f:
        pixel_values = [int(line.strip()) for line in f]
    return pixel_values

# Read pixel values from the .dat file
print("Reading pixel values from the .dat file: " + dloc + outdat)
pixel_values = read_dat(dloc + outdat)

# Create a new grayscale image from pixel values
print("Creating image from pixel values")
image = Image.new("L", (width, height))
image.putdata(pixel_values)

# Save the image
#comment unused syntax
grey_fname = "grey_" + fname
new_fname = "new_" + fname
new_loc = loc + new_fname
print("Saving image: " + new_loc)
image.save(new_loc)

print("Image saved successfully.")