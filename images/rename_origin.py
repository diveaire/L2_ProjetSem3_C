import os

folder = r"rename/"
# Listing the files of a folder
theme_list = os.listdir(folder)

# rename each file one by one
for theme in theme_list:
	word_list = os.listdir(folder + theme + "/")
	for word_folder in word_list:
            img_list = os.listdir(folder + theme + "/" + word_folder +"/")
            count = 1
            for img in img_list:
                old_name = folder + theme + "/" + word_folder + "/" + img
                new_name = folder + theme + "/" + word_folder + "/" + str(count) + ".jpg"
                os.rename(old_name, new_name)
                count+=1
print('Rename Done')
