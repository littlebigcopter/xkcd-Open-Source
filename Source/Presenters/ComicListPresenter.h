//
//  ComicListPresenter.h
//  xkcd Open Source
//
//  Created by Mike on 2/18/17.
//  Copyright © 2017 Mike Amaral. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Realm/Realm.h>

@class Comic;

@protocol ComicListView <NSObject>

@required
- (void)showComic:(Comic *)comic allowingNavigation:(BOOL)allowNavigation isInteractive:(BOOL)isInteractive inPreviewMode:(BOOL)inPreviewMode;
- (void)didStartLoadingComics;
- (void)didFinishLoadingComics;
- (void)comicListDidChange:(RLMResults *)comicList;
- (void)didEncounterLoadingError;

@end

@interface ComicListPresenter : NSObject

@property (nonatomic, readonly) BOOL isFilteringFavorites;
@property (nonatomic, readonly) BOOL isSearching;
@property (nonatomic, readonly) BOOL isFilteringUnread;

- (void)attachToView:(id<ComicListView>)view;
- (void)dettachFromView:(id<ComicListView>)view;

#pragma mark - Loading
- (BOOL)isInitialLoadRequired;
- (void)handleInitialLoad;
- (void)handleShowAllComics;

#pragma mark - Selecting comics
- (void)comicSelected:(Comic *)comic inPreviewMode:(BOOL)previewMode;

#pragma mark - Unread
- (void)toggleUnread;

#pragma mark - Favorites
- (BOOL)hasFavorites;
- (BOOL)isFilteringFavorites;
- (void)toggleFilterFavorites;

#pragma mark - Searching
- (void)handleSearchBegan;
- (void)searchForComicsWithText:(NSString *)searchText;
- (void)cancelSearch;

#pragma mark - Bookmarking
- (BOOL)hasBookmark;
- (void)showBookmarkedComic;

#pragma mark - Random
- (void)showRandomComic;
- (Comic *)randomComic;

#pragma mark - Clearing cache
- (void)handleClearCache;

@end
