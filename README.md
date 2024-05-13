# Simcity
Projet Dofus

Ce projet est un projet scolaire réalisé durant ma première année d'étude à l'ECE Paris. Il s'agit d'un jeu de type Simcity réalisé en C avec la bibliothèque graphique Allegro4.4 et avec l'utilisation de la théorie des graphes.

## Présentation
Le changement d'IDE de CodeBlocks à CLion à causé quelques problèmes de fonctionnement. 
Le projet est donc actuellement en cours de réparation.
Ainsi, le projet compile cependant il n'est pas possible de lancer une partie. 

Voici quelques images présentant le projet lorsqu'il était fonctionnel:

### Chargement
![1.gif](ReadMeImages/1.gif)
### Jeu
![2.png](ReadMeImages/2.png)
![3.png](ReadMeImages/3.png)
![4.png](ReadMeImages/4.png)
![5.png](ReadMeImages/5.png)
![6.png](ReadMeImages/6.png)
![7.png](ReadMeImages/7.png)
![8.png](ReadMeImages/8.png)
![9_réseau_d_eau.png](9_r%E9seau_d_eau.png)
![10_réseau_d_électricité.png](10_r%E9seau_d_%E9lectricit%E9.png)



## Installation
### Code Blocks
Si vous utilisez code blocks, vous pouvez suivre les étapes du lien suivant:
https://fercoq.bitbucket.io/allegro/#Installation

### CLion
Si vous utilisez CLion, vous pouvez suivre les étapes suivantes:

1. Allez sur le site : https://fercoq.bitbucket.io/allegro/#Installation
2. Suivez les étapes d'installations de allegro 4.4, cependant lors de l'extraction du fichier zip, extrayez le dans le dossier bin/mingw de votre CLion, de la même manière que avec code blocks.
3. Ouvrez CLion, allez dans File -> Settings -> Build,Execution,Deployment -> Toolchains
   ![img.png](ReadMeImages/img.png)
   ![img_1.png](ReadMeImages/img_1.png)
4. Dans toolset, choisissez MinGW que vous avez installé avec allegro dans le dossier bin/mingw de CLion.
   ![img_2.png](ReadMeImages/img_2.png)
   (Dans cet exemple le chemin est C:\MinGW)
5. Cliquez sur Apply puis OK
