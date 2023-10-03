/**
 * @file at01_myClass_Image.cc
 * @author Matheus Vargas Volpon Berto
 * @brief Esta classe contém métodos que geram arquivo de extensão .ppm para três imagens simples distintas, conforme expecificação da atividade.
 * @version 1.0.0
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "at01_myClass_Image.h"

#include <png.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Gera um arquivo .ppm para o primeiro tipo de imagem simples: um degradê.
 *
 * @param filename Nome desejado para o arquivo de saída.
 */
void myClass_Image::RenderImageFade(std::string filename) {
    // Criando um arquivo de saída .ppm
    std::ofstream arquivo(filename);

    // Escrevendo o cabeçalho .ppm
    arquivo << "P3" << std::endl;
    arquivo << width << " " << height << std::endl;
    arquivo << "255" << std::endl;

    // Gerando o degradê de roxo para azul e escreva os pixels no arquivo
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int vermelho = 128;           // Componente Vermelho fixo
            int verde = 0;                // Componente Verde fixo
            int azul = x * 255 / width;   // Varie o componente Azul de 0 a 255

            arquivo << vermelho << " " << verde << " " << azul << " ";
        }
        arquivo << std::endl;
    }

    arquivo.close();

    std::cout << "Arquivo " << filename << " gerado com sucesso.\n"
              << std::endl;
};

/**
 * @brief Gera um arquivo .ppm para o primeiro tipo de imagem simples: um retângulo sobre um fundo plano.
 *
 * @param filename Nome desejado para o arquivo de saída.
 */
void myClass_Image::RenderImageRectangule(std::string filename) {
    // Criando um arquivo de saída .ppm
    std::ofstream arquivo(filename);

    // Escrevendo o cabeçalho .ppm
    arquivo << "P3" << std::endl;
    arquivo << width << " " << height << std::endl;
    arquivo << "255" << std::endl;

    // Cores
    int verde = 0;
    int vermelho = 255;
    int marrom_r = 139;
    int marrom_g = 69;
    int marrom_b = 19;

    // Dimensões do quadrado
    int lado_quadrado = std::min(width, height) / 2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Verificando se o ponto está na metade esquerda ou direita
            if (x < width / 2) {
                arquivo << verde << " " << vermelho << " 0 ";
            } else {
                // Verifique se o ponto está dentro do quadrado
                int centro_x = width / 2;
                int centro_y = height / 2;
                int metade_lado_quadrado = lado_quadrado / 2;
                if (std::abs(x - centro_x) <= metade_lado_quadrado &&
                    std::abs(y - centro_y) <= metade_lado_quadrado) {
                    arquivo << marrom_r << " " << marrom_g << " " << marrom_b
                            << " ";
                } else {
                    arquivo << verde << " " << vermelho << " 0 ";
                }
            }
        }
        arquivo << std::endl;
    }

    arquivo.close();

    std::cout << "Arquivo " << filename << " gerado com sucesso.\n"
              << std::endl;
};

/**
 * @brief Gera um arquivo .ppm para o primeiro tipo de imagem simples: uma linha sobre um fundo plano.
 *
 * @param filename Nome desejado para o arquivo de saída.
 */
void myClass_Image::RenderImageLine(std::string filename) {
    // Criando um arquivo de saída .ppm
    std::ofstream arquivo(filename);

    // Escrevendo o cabeçalho .ppm
    arquivo << "P3" << std::endl;
    arquivo << width << " " << height << std::endl;
    arquivo << "255" << std::endl;

    // Cor do fundo vermelho
    int fundo_r = 255;
    int fundo_g = 0;
    int fundo_b = 0;

    // Cor da linha branca
    int linha_r = 255;
    int linha_g = 255;
    int linha_b = 255;

    // Posição vertical da linha
    int linha_y = height / 2;

    // Gerando a imagem com fundo vermelho e a linha branca
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (y == linha_y) {
                // Desenha a linha branca
                arquivo << linha_r << " " << linha_g << " " << linha_b << " ";
            } else {
                // Fundo vermelho
                arquivo << fundo_r << " " << fundo_g << " " << fundo_b << " ";
            }
        }
        arquivo << std::endl;
    }

    arquivo.close();

    std::cout << "Arquivo " << filename << " gerado com sucesso.\n"
              << std::endl;
};