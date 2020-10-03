clc;
clear all;
close all;
he = imread('test.JPG');
subplot(3, 2, 1);
imshow(he), title('Chlorophyll image');

 lab_he = rgb2lab(he);
 ab = lab_he(:,:,2:3);
ab = im2single(ab);
nColors = 5;
% repeat the clustering 5 times to avoid local minima
  pixel_labels = imsegkmeans(ab,nColors,'NumAttempts',5);

% pixel_labels = kmeans(ab,nColors,'NumAttempts',3);
imshow(pixel_labels,[])
title('Image Labeled by Cluster Index');
mask1 = pixel_labels==1;
cluster1 = he .* uint8(mask1);
subplot(3, 2, 2);
imshow(cluster1)
title('Objects in Cluster 1');
Imgv1 = reshape(cluster1(:,:,1), [], 1);
Black_pxl = sum(Imgv1 == 0)
White_pxl = numel(Imgv1)-Black_pxl
MyocardArea1 = bwarea(cluster1(:,:,1))


mask2 = pixel_labels==2;
cluster2 = he .* uint8(mask2);
subplot(3, 2, 3);
imshow(cluster2)
title('Objects in Cluster 2');
Imgv2 = reshape(cluster2(:,:,1), [], 1);
Black_px2 = sum(Imgv2 == 0)
White_px2 = numel(Imgv2)-Black_px2
MyocardArea2 = bwarea(cluster2(:,:,1))


mask3 = pixel_labels==3;
cluster3 = he .* uint8(mask3);
subplot(3, 2, 4);
imshow(cluster3)
title('Objects in Cluster 3');
Imgv3 = reshape(cluster3(:,:,1), [], 1);
Black_px3 = sum(Imgv3 == 0)
White_px3 = numel(Imgv3)-Black_px3
MyocardArea3 = bwarea(cluster3(:,:,1))



mask4 = pixel_labels==4;
cluster4 = he .* uint8(mask4);
subplot(3, 2, 5);
imshow(cluster4)
title('Objects in Cluster 4');
Imgv4 = reshape(cluster4(:,:,1), [], 1);
Black_px4 = sum(Imgv4 == 0)
White_px4 = numel(Imgv4)-Black_px4
MyocardArea4 = bwarea(cluster4(:,:,1))


mask5 = pixel_labels==5;
cluster5 = he .* uint8(mask5);
subplot(3, 2, 6);
imshow(cluster5)
title('Objects in Cluster 5');
Imgv5 = reshape(cluster5(:,:,1), [], 1);
Black_px5 = sum(Imgv5 == 0)
White_px5 = numel(Imgv5)-Black_px5
MyocardArea5 = bwarea(cluster5(:,:,1))

