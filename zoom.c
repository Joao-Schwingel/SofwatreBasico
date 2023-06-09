#include <stdio.h>
#include "lib_ppm.h"

static int Setcor(int cor, int *vetor);
int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s new_data;
	struct image_s *new_image = &new_data;
	int altura = 0;
	int largura = 0;
	int r;

	r = read_ppm("teste.ppm", image);

	new_ppm(new_image, image->width * 3, image->height * 3);

		if (r == 0)
	{
		for (int j = 0; j < image->height; j++)
		{
			for (int i = 0; i < image->width; i++)
			{
				int indice = j * image->width + i;

				int red = image->pix[indice].r;
				int green = image->pix[indice].g;
				int blue = image->pix[indice].b;

				int r_vetor[3];
				int g_vetor[3];
				int b_vetor[3];
				Setcor(red, r_vetor);
				Setcor(green, g_vetor);
				Setcor(blue, b_vetor);

				setRed(new_image, altura, largura, r_vetor);
				setGreen(new_image, altura, largura, g_vetor);
				setBlue(new_image, altura, largura, b_vetor);

				largura = largura + 3;
			}
			largura = 0;
			altura = altura + 3;
		}
		write_ppm("resultado.ppm", new_image);
	}
	return 0;
}

void setRed(struct image_s *new_image, int altura, int largura, int *r_vetor)
{
	new_image->pix[altura * new_image->width + largura].r = r_vetor[0]; // pixels r
	new_image->pix[(altura + 1) * new_image->width + largura].r = r_vetor[1];
	new_image->pix[(altura + 2) * new_image->width + largura].r = r_vetor[2];
}

void setGreen(struct image_s *new_image, int altura, int largura, int *g_vetor)
{
	new_image->pix[altura * new_image->width + (largura + 1)].g = g_vetor[0]; // pixels g
	new_image->pix[(altura + 1) * new_image->width + (largura + 1)].g = g_vetor[1];
	new_image->pix[(altura + 2) * new_image->width + (largura + 1)].g = g_vetor[2];
}

void setBlue(struct image_s *new_image, int altura, int largura, int *b_vetor)
{
	new_image->pix[altura * new_image->width + (largura + 2)].b = b_vetor[0]; // pixels b
	new_image->pix[(altura + 1) * new_image->width + (largura + 2)].b = b_vetor[0];
	new_image->pix[(altura + 2) * new_image->width + (largura + 2)].b = b_vetor[0];
}

int Setcor(int cor, int *vetor)
{
	if (cor <= 74)
	{
		vetor[0] = 0;
		vetor[1] = 0;
		vetor[2] = 0;
		return 0;
	}
	if (cor <= 134)
	{
		vetor[0] = 0;
		vetor[1] = 255;
		vetor[2] = 0;

		return 0;
	}
	if (cor <= 179)
	{
		vetor[0] = 255;
		vetor[1] = 0;
		vetor[2] = 255;

		return 0;
	}
	vetor[0] = 255;
	vetor[1] = 255;
	vetor[2] = 255;
	return 0;
}