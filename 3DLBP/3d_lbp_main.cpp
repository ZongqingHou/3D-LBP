//
// Created by hdd on 2020-11-05.
//

#include <fstream>
#include <Eigen/Core>
#include <Open3D/Open3D.h>

#define TEST_PATH "/home/file_collections/gitlab/3D-LBP/face_mesh_vertexcolour.obj"
#define SELECTED_FACE_INDEX 100
#define INIT_RING_NUMBER 3
#define FACET_NUMBER 12

using namespace open3d;

std::vector<Eigen::Vector3i> bridge(const std::vector<Eigen::Vector3i>& mesh_array, ){

}

int main(int argc, char** argv){
    std::shared_ptr<geometry::TriangleMesh> tmp_mesh_read_ptr_i = std::make_shared<geometry::TriangleMesh>();

    tmp_mesh_read_ptr_i->Clear();
    if (!io::ReadTriangleMeshFromOBJ(TEST_PATH, *tmp_mesh_read_ptr_i, true)) {
        return 1;
    }
    visualization::DrawGeometries({tmp_mesh_read_ptr_i});

    auto mesh_array = (* tmp_mesh_read_ptr_i).triangles_;
    auto pc_array = (* tmp_mesh_read_ptr_i).vertices_;

    auto selected_face = mesh_array[SELECTED_FACE_INDEX];

    std::cout << selected_face << std::endl;

    int ring_number_cnt = INIT_RING_NUMBER;
    while (ring_number_cnt > 0){
        for(int i = 0; i < mesh_array.size(); ++i){

        }
        ring_number_cnt--;
    }

//    for (int i = 0; i < mesh_array.size(); ++i){
//        if (){
//
//        }
//    }

    return 0;
}