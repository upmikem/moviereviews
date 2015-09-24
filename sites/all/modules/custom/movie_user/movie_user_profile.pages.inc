<?php

/*
 * Return a render array
 */
function movie_user_preferences($uid) {
  $output = array();

  $user_object = user_load($uid);
  //dpm($user_object);

  //get the user preferences
  $user_preference = movie_user_get_user_details($uid);
  //dpm($user_preference);

  if(!empty($user_object->name)){
    $output[] = array(
        '#type' => 'markup',
        '#markup' => theme('user_preference_title', array('username' => $user_object->name)),
    );
  }

  //use node_load to load the film details

  if(!empty($user_preference['film_nid'])) {
    $favorite_film = node_load($user_preference['film_nid']);

    $film_details = array(
        'title' => $favorite_film->title,
        'plot' =>  $favorite_film->field_movie_review_plot[LANGUAGE_NONE][0]['value'],
        'image' => theme('image_style', array('style_name' => 'thumbnail', 'path' => $favorite_film->field_movie_review_poster[LANGUAGE_NONE][0]['uri'])),
    );
    $output[] = array(
        '#type' => 'markup',
        '#markup' => theme('fav_film_teaser', $film_details),
      );
    }

  //dpm($user_preference);
  if(!empty($user_preference['genres_tid'])) {

    drupal_set_title(t("!user's film preferences", array('!user' => $user_object->name)));

    $output[] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="suggested-film-title">',
        '#markup' => '<h3>' . t('suggestions for !username', array('!username' => $user_object->name)) . '</h3>',
        '#suffix' => '<input type="button" data-uid="' . $user_object->uid . '" class="suggest-more-button" value="' . t('Suggest More') . '"/>' . '</div>',
       );
    $output[] = array(
        '#type' => 'markup',
        '#markup' => movie_user_get_preferences($uid),
        '#prefix' => '<div class="movie-suggestions-by-genre">',
        '#suffix' => '</div>',
      );
    // include the movie_user.js file
    $output['ajax_js_file']['#attached']['js'][drupal_get_path('module', 'movie_user') . '/movie_user.js'] = array('preprocess' => TRUE);

    // create the javascript setting for the suggest callback
    $output['ajax_js_settings']['#attached']['js'][] = array(
      'type' => 'setting',
        'data' => array(
          'movie_suggest_url' => 'suggestmovies',
          ),
      );
  }

//  $view = movie_user_get_preferences($uid);
//  dpm($view);
  return $output;
}







