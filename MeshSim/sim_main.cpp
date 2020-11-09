//
// Created by hdd on 2020-11-05.
//

#include <fstream>
#include <Eigen/Core>
#include <Open3D/Open3D.h>

#define TEST_PATH "/home/file_collections/gitlab/3D-LBP/face_mesh_vertexcolour.obj"
#define TARGET_SIZE 1024

using namespace open3d;

int main(int argc, char** argv){
    std::shared_ptr<geometry::TriangleMesh> tmp_mesh_read_ptr_i = std::make_shared<geometry::TriangleMesh>();

    tmp_mesh_read_ptr_i->Clear();
    if (!io::ReadTriangleMeshFromOBJ(TEST_PATH, *tmp_mesh_read_ptr_i, true)) {
        return 1;
    }
    visualization::DrawGeometries({tmp_mesh_read_ptr_i});

    auto mesh_array = (* tmp_mesh_read_ptr_i).triangles_;
    auto pc_array = (* tmp_mesh_read_ptr_i).vertices_;

    if((* tmp_mesh_read_ptr_i).HasAdjacencyList()){

    }else{
        std::vector<std::unordered_set<int>> tmp_adjacency_list;
        for (int i = 0; i < pc_array.size(); ++i) {
            std::unordered_set<int> tmp_set;
            tmp_adjacency_list.push_back(tmp_set);
        }

        for (int i = 0; i < mesh_array.size(); ++i) {
            Eigen::Vector3i tmp_face = mesh_array[i];
            int tmp_face_size = tmp_face.size();
            for(int j = 0; j < tmp_face_size; ++j){
                tmp_adjacency_list[tmp_face[j]].insert(tmp_face[(j + 1) % tmp_face_size]);
                tmp_adjacency_list[tmp_face[j]].insert(tmp_face[(j + 2) % tmp_face_size]);
            }
        }

//        (* tmp_mesh_read_ptr_i).adjacency_list_ = tmp_adjacency_list;
        auto tmp = (* tmp_mesh_read_ptr_i).ComputeAdjacencyList().adjacency_list_;
        std::cout << "Pause" << std::endl;
    }
    int pc_size = pc_array.size();
    while(pc_size >= TARGET_SIZE){

    }

//    while (ring_number_cnt > 0){
//        for(int i = 0; i < mesh_array.size(); ++i){
//
//        }
//        ring_number_cnt--;
//    }

    auto tmp = (* tmp_mesh_read_ptr_i).HasAdjacencyList();

//    for (int i = 0; i < tmp.size(); ++i){
//        std::cout << tmp[i] << std::endl;
//    }

    return 0;
}